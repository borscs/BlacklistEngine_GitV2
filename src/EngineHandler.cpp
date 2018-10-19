#include <err.h>
#include "EngineHandler.h"

int EngineHandler::scan( const QString &path )
{
	QFileInfo directory(path);

	if (!QFileInfo::exists(path)  ||  directory.isDir()) {
		utils.qStdOut() << path<<": "<<ERROR_FILE_NOT_FOUND<<endl;
		return 1;
	}
	jsonHelper.onylOnePrint(getResultAndScan(path), path);
	return 0;
}

int EngineHandler::lookup( const QString &hash )
{
	if (hash.isEmpty()){
		return 1;
	}
	if ( engine.lookup(hash)) {
		jsonHelper.onylOnePrint(BLOCKED, hash);
	}
	else {
		jsonHelper.onylOnePrint(NO_THREAT_DETECTED, hash);
	}
	return 0;
}

int EngineHandler::generate( const QString &path )
{
	if (!QFileInfo::exists(path)) {
		return 1;
	}
	jsonHelper.clearJson();
	jsonHelper.addToJson("file_name", path);
	jsonHelper.addToJson("md5", engine.fileHashGenerate(path, QCryptographicHash::Md5));
	jsonHelper.addToJson("sha1", engine.fileHashGenerate(path, QCryptographicHash::Sha1));
	jsonHelper.addToJson("sha256", engine.fileHashGenerate(path, QCryptographicHash::Sha256));

	utils.qStdOut() << jsonHelper.createJson().toJson();

	if(!engine.addRecord(jsonHelper.getRecordObject().value("md5").toString(),
								   jsonHelper.getRecordObject().value("sha1").toString(),
								   jsonHelper.getRecordObject().value("sha256").toString(),
								   jsonHelper.getRecordObject().value("file_name").toString())){

		utils.qStdOut()<< "Adding record failed";
	}
	
	return 0;

}

int EngineHandler::scanFolder( QString path )
{
	jsonHelper.clearJson();
	QFileInfo directory(path);

	if (directory.isDir()) {

		QStringList results = utils.fileInFolder(path);
		jsonHelper.clearJson();

		for ( auto &result : results ) {

			jsonHelper.pushbackToArray(result, getResultAndScan(result));
			jsonHelper.getQJsonArray().push_back(jsonHelper.getRecordObject());

		}
		utils.qStdOut() << jsonHelper.createJson(jsonHelper.getQJsonArray()).toJson();


		return 0;
	}
	else {
		jsonHelper.onylOnePrint(NO_FOLDER, path);
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

