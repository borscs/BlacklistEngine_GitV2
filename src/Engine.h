#pragma once

#include <QCryptographicHash>

#include "Database.h"

class Engine
{
public:
	bool init();
	bool lookup(QString hash);
	int fileScan(QString path);
	QMap<QString, QString> hashes(const QString &path);
	QString fileHashGenerate(QString path, QCryptographicHash::Algorithm algorithm);
	Database &getDatabase();

private:
	Database database;
};