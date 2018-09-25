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

			break;
		case static_cast<int>(utils::Verdict ::Error):

			break;
		default:
			break;
	}
}

