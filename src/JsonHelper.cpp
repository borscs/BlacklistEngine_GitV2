#include "JsonHelper.h"

#include <QVariant>


void JsonHelper::clearJson()
{
	recordObject = QJsonObject();
}

void JsonHelper::addToJson(const QString &tag, const QString &data)
{

	QVariant qvariant(data);
	recordObject.insert(tag,QJsonValue::fromVariant(qvariant));
}

QJsonDocument JsonHelper::createJson(QJsonArray array)
{
	QJsonObject jsonObject;
	jsonObject.insert("Scanning resutl", array);
	QJsonDocument jsonDocument(jsonObject);
	utils.qStdOut() << jsonDocument.toJson();
}

void JsonHelper::createJson()
{
	QJsonObject jsonObject;
	jsonObject.insert("Scanning resutl", recordObject);
	QJsonDocument jsonDocument(jsonObject);
	utils.qStdOut()	 <<  jsonDocument.toJson();
}
void JsonHelper::pushbackToArray( const QString &result, const QString &string )
{
	addToJson("File_name", result);
	addToJson("Verdict",  string);

}


void JsonHelper::onylOnePrint( const QString &hashes, const QString &string)
{

	clearJson();
	addToJson("Hows detected", string);
	addToJson("Verdict", hashes);
	createJson();

}
