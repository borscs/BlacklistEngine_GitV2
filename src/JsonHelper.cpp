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
	jsonObject.insert(scan, array);
	QJsonDocument jsonDocument(jsonObject);
	return jsonDocument;
}

QJsonDocument JsonHelper::createJson()
{
	QJsonObject jsonObject;
	jsonObject.insert(scan, recordObject);
	QJsonDocument jsonDocument(jsonObject);
	return  jsonDocument;
}
void JsonHelper::pushbackToArray( const QString &result, const QString &string )
{
	addToJson(filename, result);
	addToJson(verdict,  string);
}

void JsonHelper::onylOnePrint( const QString &hashes, const QString &string)
{
	clearJson();
	addToJson(filename, string);
	addToJson(verdict, hashes);
	getUtils().qStdOut()<< createJson().toJson(QJsonDocument::Indented);
}

QJsonObject &JsonHelper::getRecordObject()
{
	return recordObject;
}

QJsonArray &JsonHelper::getQJsonArray()
{
	return qJsonArray;
}

utils::Utils &JsonHelper::getUtils()
{
	return utils;
}
