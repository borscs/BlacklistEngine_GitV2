#include "EngineHandler.h"

int EngineHandler::scan( const QString &path )
{
	if (!QFileInfo::exists(path)) {
		return 1;
	}
	jsonHelper.onylOnePrint(getResult(path), path);
	return 0;
}

int EngineHandler::lookup( const QString &hash )
{
	if (hash.isEmpty()){
		return 1;
	}
	if ( engine.lookup(hash)) {
		jsonHelper.onylOnePrint(blocked, hash);
		return 0;
	}
	else {
		jsonHelper.onylOnePrint(noThread, hash);
		return 0;
	}

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

	engine.getDatabase().addRecord(jsonHelper.getRecordObject().value("md5").toString(),
								   jsonHelper.getRecordObject().value("sha1").toString(),
								   jsonHelper.getRecordObject().value("sha256").toString(),
								   jsonHelper.getRecordObject().value("file_name").toString()
	);
	return 0;

}

int EngineHandler::scanFolder( QString path )
{
	jsonHelper.clearJson();

	if ( !QFileInfo::exists(path)) {
		jsonHelper.onylOnePrint(path, ERROR_FILE_NOT_FOUND);
		return 1;
	}

	QStringList results = utils.fileInFolder(path);

	jsonHelper.clearJson();

	for ( auto &result : results ) {

		jsonHelper.pushbackToArray(result, getResult(result));
		jsonHelper.getQJsonArray().push_back(jsonHelper.getRecordObject());

	}
	utils.qStdOut() << jsonHelper.createJson(jsonHelper.getQJsonArray()).toJson();


	return 0;
}
QString EngineHandler::getResult( const QString &path )
{
	switch ( engine.fileScan(path)) {
		case static_cast<int>(utils::Verdict::Clear):
			return noThread;
		case static_cast<int>(utils::Verdict::Threat):
			return blocked;
		default:
			return ERROR_FILE_NOT_FOUND;
	}
}

