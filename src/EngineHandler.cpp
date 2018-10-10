#include "EngineHandler.h"

bool EngineHandler::scan(const QString &path)
{
	switch (engine.fileScan(path)) {
		case 0 :
			jsonHelper.onylOnePrint(noTread, path);
			break;
		case 1:
			jsonHelper.onylOnePrint(blocked, path);
			break;
		case 2:
			jsonHelper.onylOnePrint(file, path);
			break;
		default:
			break;
	}
	return true;
}

bool EngineHandler::lookup(const QString &hash)
{
	if(!QFileInfo::exists(hash)) {
		if ( !engine.lookup(hash)) {
			jsonHelper.onylOnePrint(blocked, hash);
		}
		else {
			jsonHelper.onylOnePrint(noTread, hash);
		}
	}
	else{
		jsonHelper.onylOnePrint(file, hash);
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

	engine.getDatabase().addRecord(jsonHelper.recordObject.value("md5").toString(),
								   jsonHelper.recordObject.value("sha1").toString(),
								   jsonHelper.recordObject.value("sha256").toString(),
								   jsonHelper.recordObject.value("file_name").toString()
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
		switch (engine.fileScan(result)) {
			case static_cast<int>(utils::Verdict::Clear):
				jsonHelper.pushbackToArray(result, noTread);
				jsonHelper.qJsonArray.push_back(jsonHelper.recordObject);
				break;
			case static_cast<int>(utils::Verdict::Threat):
				jsonHelper.pushbackToArray(result, blocked);
				jsonHelper.qJsonArray.push_back(jsonHelper.recordObject);
				break;
			case static_cast<int>(utils::Verdict::Error):
				jsonHelper.pushbackToArray(result, error);
				jsonHelper.qJsonArray.push_back(jsonHelper.recordObject);
				break;
			default:
				break;
		}
	}
	jsonHelper.createJson(jsonHelper.qJsonArray);


	return false;
}

