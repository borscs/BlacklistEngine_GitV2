#pragma once

#include <QCryptographicHash>

#include "Database.h"

class Engine
{
public:
	bool init();
	bool lookup(QString hash);
	int fileScan(QString path);
	QMap<QString, QString> getHashes(const QString &path);
	QString fileHashGenerate(QString path, QCryptographicHash::Algorithm algorithm);
	bool addRecord(const QString &md5, const QString  &sha1, const QString &sha256,const QString &name);
private:
	Database database;
};