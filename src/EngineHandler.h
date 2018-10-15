#pragma once

#include <QString>
#include <QtDebug>
#include <QFileInfo>

#include "Engine.h"
#include "Utils.h"
#include "JsonHelper.h"

static const QString blocked("Blocked");
static const QString noTread("No threat Detected");
static const QString error("File not found");
static const QString file("This not hash");

class EngineHandler
{
public:
	int scan(const QString &path);
	int generate(const QString &path);
	int lookup(const QString &hash);
	int scanFolder(QString path);
private:
	QString switchcase(const QString &path);
private:
	Engine engine;
	utils::Utils utils;
	JsonHelper jsonHelper;




};