#pragma once

#include <QString>
#include <QtDebug>
#include <QFileInfo>

#include "Engine.h"
#include "Utils.h"
#include "JsonHelper.h"

static const QString BLOCKED("Blocked");
static const QString NO_THREAT_DETECTED("No threat Detected");
static const QString ERROR_FILE_NOT_FOUND("File not found");
static const QString NOT_FOLDER("Not Folder");

class EngineHandler
{
public:
	int scan(const QString &path);
	int generate(const QString &path);
	int lookup(const QString &hash);
	int scanFolder(QString path);
private:
	QString getResultAndScan(const QString &path);
private:
	Engine engine;
	utils::Utils utils;
};