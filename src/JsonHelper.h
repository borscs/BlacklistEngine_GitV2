
#pragma once
#include "Utils.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QCoreApplication>
#include <QJsonObject>

static const QString filename("Filename");
static const QString verdict("Verdict");
static const QString scan("Scanning result");




class JsonHelper
{

public:


	void clearJson();
	void addToJson(const QString &tag,const QString &data);
	QJsonDocument createJson(QJsonArray array);
	QJsonDocument createJson();
	void onylOnePrint(const QString  &hashes, const QString &string);
	void pushbackToArray(const QString &result, const QString &string);
public:
	QJsonObject recordObject;
	QJsonArray qJsonArray;
	utils::Utils utils;
};
