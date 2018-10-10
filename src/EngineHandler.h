#pragma once

#include <QString>
#include <QtDebug>
#include <QFileInfo>

#include "Engine.h"
#include "Utils.h"
#include "JsonHelper.h"

static const QString blocked("Blocked");
static const QString noTread("No thread Detected");
static const QString error("File no found");
static const QString file("This not hashes");

class EngineHandler
{
public:


	bool scan(const QString &path);
	bool generate(const QString &path);
	bool lookup(const QString &hash);
	bool scanFolder(QString path);

private:

	Engine engine;
	utils::Utils utils;
	JsonHelper jsonHelper;




};