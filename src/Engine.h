#pragma once

#include <QCryptographicHash>

#include "Database.h"

class Engine
{
public:

	bool init();
	bool lookup(QString hash);
	int fileScan(QString path);
	QMap<QString, QString> hashes(const QString &path, const QString &hashes);
	QString fileHashGenerate(QString path, QCryptographicHash::Algorithm algorithm);

private:

	Database database;
public:
	const Database &getDatabase() const;
};