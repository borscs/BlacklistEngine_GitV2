#pragma once

#include <QString>
#include <QtDebug>
#include <QFileInfo>

#include "Engine.h"
#include "Utils.h"
#include "JsonHelper.h"

static const QString blocked("Blocked");
static const QString noThread("No threat Detected");
static const QString ERROR_FILE_NOT_FOUND("File not found");

class EngineHandler
{
public:
	int scan(const QString &path);
	int generate(const QString &path);
	int lookup(const QString &hash);
	int scanFolder(QString path);
private:
	QString getResult(const QString &path);
private:
	Engine engine;
	utils::Utils utils;
	JsonHelper jsonHelper;
};