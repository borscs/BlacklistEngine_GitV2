#pragma once

#include <QString>
#include <QtDebug>
#include <QFileInfo>

#include "Engine.h"
#include "Utils.h"
#include "JsonHelper.h"

class EngineHandler
{
public:

	void scan(const QString &path);
	void generate(const QString &path);
	void lookup(const QString &hash);

private:

	Engine engine;
	utils::Utils utils;
	JsonHelper jsonHelper;

};