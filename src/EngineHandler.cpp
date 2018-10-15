#include "EngineHandler.h"

bool EngineHandler::scan(const QString &path)
{

	jsonHelper.onylOnePrint(switchcase(path), path);
}

bool EngineHandler::lookup(const QString &hash)
{

		if ( engine.lookup(hash)) {
			jsonHelper.onylOnePrint(blocked, hash);
		}
		else {
			jsonHelper.onylOnePrint(noTread, hash);
		}

	return true;
}

bool EngineHandler::generate(const QString &path)
{
	jsonHelper.clearJson();
	jsonHelper.addToJson("file_name", path);
	jsonHelper.addToJson("md5", engine.fileHashGenerate(path, QCryptographicHash::Md5));
	jsonHelper.addToJson("sha1", engine.fileHashGenerate(path, QCryptographicHash::Sha1));
	jsonHelper.addToJson("sha256", engine.fileHashGenerate(path, QCryptographicHash::Sha256));

	utils.qStdOut() <<  jsonHelper.createJson().toJson();

	engine.getDatabase().addRecord(jsonHelper.getRecordObject().value("md5").toString(),
								   jsonHelper.getRecordObject().value("sha1").toString(),
								   jsonHelper.getRecordObject().value("sha256").toString(),
								   jsonHelper.getRecordObject().value("file_name").toString()
								   );

	return true;
}

bool EngineHandler::scanFolder( QString path )
{
	jsonHelper.clearJson();

	if (!QFileInfo::exists(path)) {
		jsonHelper.onylOnePrint(path, error);
		return false;
	}

	QStringList results = utils.fileInFolder(path);

	jsonHelper.clearJson();

	for (auto &result : results) {

		jsonHelper.pushbackToArray(result, switchcase(result));
		jsonHelper.getQJsonArray().push_back(jsonHelper.getRecordObject());

	}
	utils.qStdOut() <<  jsonHelper.createJson(jsonHelper.getQJsonArray()).toJson();


	return false;
}
QString EngineHandler::switchcase( const QString &path )
{
	switch (engine.fileScan(path)) {
		case static_cast<int>(utils::Verdict::Clear):
			return noTread;
		case static_cast<int>(utils::Verdict::Threat):
			 return blocked;
		default:
			return  error;
	}
}

