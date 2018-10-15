#include "Engine.h"
#include "Utils.h"

#include "iostream"
bool Engine::init()
{
	return database.connectToDatabase();
}

bool Engine::lookup( QString hash )
{
	return database.findInDatabase(hash);
}

int Engine::fileScan( QString path )
{
	if (!QFileInfo::exists(path)) {
		return static_cast<int>(utils::Verdict::Error);
	}

	QMap<QString, QString> qmap = hashes(path);

	if (database.findInDatabase(qmap["md5"], qmap["sha1"], qmap["sha256"])) {
		return static_cast<int>(utils::Verdict::Threat);
	}
	else {
		return static_cast<int >(utils::Verdict::Clear);
	}
}

QMap<QString, QString> Engine::hashes(const QString &path)
{
	QMap<QString, QString> qmap;
		qmap["md5"] = fileHashGenerate(path, QCryptographicHash::Algorithm::Md5);
		qmap["sha1"] = fileHashGenerate(path, QCryptographicHash::Algorithm::Sha1);
		qmap["sha256"] = fileHashGenerate(path, QCryptographicHash::Algorithm::Sha256);

	return qmap;
}
QString Engine::fileHashGenerate( QString path, QCryptographicHash::Algorithm hashAlgoritm )
{
	QFile file(path);
	if (file.open(QFile::ReadOnly)) {
		QCryptographicHash hash(hashAlgoritm);
		if (hash.addData(&file)) {
			return hash.result().toHex();
		}
	}

	return QString();
}
 Database &Engine::getDatabase()
{
	return database;
}

