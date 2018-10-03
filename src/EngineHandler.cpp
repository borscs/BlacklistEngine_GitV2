#include "EngineHandler.h"

void EngineHandler::scan(const QString &path)
{
	switch (engine.fileScan(path)) {
		case 0 :
			jsonHelper.onylOnePrint("No threat detected", path);
			break;
		case 1:
			jsonHelper.onylOnePrint("The file blocked", path);
			break;
		case 2:
			jsonHelper.onylOnePrint("File no found", path);
			break;
		default:
			break;
	}
}

void EngineHandler::lookup(const QString &hash)
{
	if(!QFileInfo::exists(hash)) {
		if ( engine.lookup(hash)) {
			jsonHelper.onylOnePrint("The file blocked", hash);
		}
		else {
			jsonHelper.onylOnePrint("No threat detected", hash);
		}
	}
	else{
		jsonHelper.onylOnePrint("This file", hash);
	}
}

void EngineHandler::generate(const QString &path)
{
	jsonHelper.clearJson();
	jsonHelper.addToJson("file_name", path);
	jsonHelper.addToJson("md5", engine.fileHashGenerate(path, QCryptographicHash::Md5));
	jsonHelper.addToJson("sha1", engine.fileHashGenerate(path, QCryptographicHash::Sha1));
	jsonHelper.addToJson("sha256", engine.fileHashGenerate(path, QCryptographicHash::Sha256));
	jsonHelper.createJson();
	engine.database.addRecord(jsonHelper.recordObject.value("md5").toString(),
								   jsonHelper.recordObject.value("sha1").toString(),
								   jsonHelper.recordObject.value("sha256").toString(),
								   jsonHelper.recordObject.value("file_name").toString()
								   );
}

bool EngineHandler::scanFolder( QString path )
{
	jsonHelper.clearJson();

	if (!QFileInfo::exists(path)) {
		utils.qStdOut() << "Folder not found!";
		return false;
	}

	QStringList results = utils.fileInFolder(path);

	jsonHelper.clearJson();

	for (auto &result : results) {
		switch (engine.fileScan(result)) {
			case static_cast<int>(utils::Verdict::Clear):
				jsonHelper.pushbackToArray(result, "No threat detected");
				jsonHelper.qJsonArray.push_back(jsonHelper.recordObject);
				break;
			case static_cast<int>(utils::Verdict::Threat):
				jsonHelper.pushbackToArray(result, "Blocked");
				jsonHelper.qJsonArray.push_back(jsonHelper.recordObject);
				break;
			case static_cast<int>(utils::Verdict::Error):
				jsonHelper.pushbackToArray(result, "File not found!");
				jsonHelper.qJsonArray.push_back(jsonHelper.recordObject);
				break;
			default:
				break;
		}
	}
	jsonHelper.createJson(jsonHelper.qJsonArray);


	return false;
}

