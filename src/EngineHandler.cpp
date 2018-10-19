#include <err.h>
#include "EngineHandler.h"

int EngineHandler::scan( const QString &path )
{
	QFileInfo directory(path);

	if ( !QFileInfo::exists(path) || directory.isDir()) {
		utils.qStdOut() << path << ": " << ERROR_FILE_NOT_FOUND << endl;
		return 1;
	}
	utils.qStdOut() << path <<": "<<getResultAndScan(path)<<endl;
	return 0;
}

int EngineHandler::lookup( const QString &hash )
{
	if (hash.isEmpty()) {
		return 1;
	}
	if (engine.lookup(hash)) {
		utils.qStdOut()<< hash << ": " << BLOCKED<<endl;
	}
	else {
		utils.qStdOut() << hash << ": " << NO_THREAT_DETECTED<<endl;
	}
	return 0;
}

int EngineHandler::generate( const QString &path )
{
	if ( !QFileInfo::exists(path)) {
		return 1;
	}
	QMap<QString, QString> hashes = engine.getHashes(path);
	utils.qStdOut() << path << ":" << endl;
	utils.qStdOut() << "md5: " << hashes["md5"] << endl;
	utils.qStdOut() << "sha1: " << hashes["sha1"] << endl;
	utils.qStdOut() << "sha256: " << hashes["sha256"] << endl;

	if ( !engine.addRecord(hashes["md5"], hashes["sha1"], hashes["sha256"], path)) {

		utils.qStdOut() << "Adding record failed";
	}

	return 0;

}

int EngineHandler::scanFolder( QString path )
{
	QFileInfo directory(path);

	if ( directory.isDir()) {

		QStringList results = utils.fileInFolder(path);
		utils.qStdOut()<<path<<": "<<endl;
		for ( auto &result : results ) {

			utils.qStdOut()<<result <<": "<< getResultAndScan(result)<<endl;

		}


		return 0;
	}
	else {
		utils.qStdOut()<<path<<": "<<NOT_FOLDER<<endl;
		return 1;
	}
}
QString EngineHandler::getResultAndScan( const QString &path )
{
	switch ( engine.fileScan(path)) {
		case static_cast<int>(utils::Verdict::Clear):
			return NO_THREAT_DETECTED;
		case static_cast<int>(utils::Verdict::Threat):
			return BLOCKED;
		default:
			return ERROR_FILE_NOT_FOUND;
	}
}

