#include "EngineHandler.h"

void EngineHandler::scan(const QString &path)
{
	switch (engine.fileScan(path)) {
		case static_cast<int>(utils::Verdict ::Clear):
			jsonHelper.clearJSON();
			jsonHelper.addToJSON("file_name", path);
			jsonHelper.addToJSON("verdict", "No threat detected");
			jsonHelper.createNode();
			utils.qStdOut() << jsonHelper.createJSON().toJson(QJsonDocument::Indented);
			break;
		case static_cast<int>(utils::Verdict ::Threat):
			jsonHelper.clearJSON();
			jsonHelper.addToJSON("file_name", path);
			jsonHelper.addToJSON("verdict", "blocked");
			jsonHelper.createNode();
			utils.qStdOut() << jsonHelper.createJSON().toJson(QJsonDocument::Indented);
			break;
		case static_cast<int>(utils::Verdict ::Error):
			jsonHelper.clearJSON();
			jsonHelper.addToJSON("file_name", path);
			jsonHelper.addToJSON("error", "file not found!");
			jsonHelper.createNode();
			utils.qStdOut() << jsonHelper.createJSON().toJson(QJsonDocument::Indented);
			break;
		default:
			break;
	}
}
void EngineHandler::generate(const QString &path)
{
	jsonHelper.clearJSON();
	jsonHelper.addToJSON("file_name", path);
	jsonHelper.addToJSON("md5", engine.fileHashGenerate(path, QCryptographicHash::Md5));
	jsonHelper.addToJSON("sha1", engine.fileHashGenerate(path, QCryptographicHash::Sha1));
	jsonHelper.addToJSON("sha256", engine.fileHashGenerate(path, QCryptographicHash::Sha256));
	jsonHelper.createNode();
	utils.qStdOut() << jsonHelper.createJSON().toJson(QJsonDocument::Indented);

	engine.getDatabase().addRecord(jsonHelper.recordObject.value("md5").toString(),
								   jsonHelper.recordObject.value("sha1").toString(),
								   jsonHelper.recordObject.value("sha256").toString(),
								   path);
}
void EngineHandler::lookup(const QString &hash)
{
	jsonHelper.clearJSON();

	if (engine.lookup(hash)) {
		jsonHelper.addToJSON("hash", hash);
		jsonHelper.addToJSON("verdict", "blocked");
		jsonHelper.createNode();
	}
	else {
		jsonHelper.addToJSON("hash", hash);
		jsonHelper.addToJSON("verdict", "No threat detected");
		jsonHelper.createNode();
	}

	utils.qStdOut() << jsonHelper.createJSON().toJson(QJsonDocument::Indented);
}
bool EngineHandler::scanFolder( QString path )
{
	if (!QFileInfo::exists(path)) {
		utils.qStdOut() << "Given folder not found!";
		return false;
	}

	QStringList results = utils.fileInFolder(path);
	jsonHelper.clearJSON();

	for (auto &result : results) {
		switch (engine.fileScan(result)) {
			case static_cast<int>(utils::Verdict::Clear):
				jsonHelper.addToJSON("file_name", result);
				jsonHelper.addToJSON("verdict", "no threat detected");
				jsonHelper.createNode();
				break;
			case static_cast<int>(utils::Verdict::Threat):
				jsonHelper.addToJSON("file_name", result);
				jsonHelper.addToJSON("verdict", "blocked");
				jsonHelper.createNode();
				break;
			case static_cast<int>(utils::Verdict::Error):
				jsonHelper.addToJSON("file_name", result);
				jsonHelper.addToJSON("error", "file not found!");
				jsonHelper.createNode();
				break;
			default:
				break;
		}
	}

	utils.qStdOut() << jsonHelper.createJSON(jsonHelper.getQJsonArray()).toJson(QJsonDocument::Indented);

	return false;
}


