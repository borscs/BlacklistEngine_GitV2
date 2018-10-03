#pragma once

#include <QCryptographicHash>

#include "Database.h"

class Engine
{
public:

	bool init();
	bool lookup(QString hash);
	int fileScan(QString path);
	QMap<QString, QString> hashes(QString path);
	QString fileHashGenerate(QString path, QCryptographicHash::Algorithm algorithm);

public:

	Database database;

};