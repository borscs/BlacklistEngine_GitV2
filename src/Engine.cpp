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

	if (database.findInDatabase(hashes(path, "md5")["md5"], hashes(path, "sha1")["sha1"], hashes(path, "sha256")["sha256"])) {
		return static_cast<int>(utils::Verdict::Threat);
	}
	else {
		return static_cast<int >(utils::Verdict::Clear);
	}
}

QMap<QString, QString> Engine::hashes(const QString &path, const QString &hashes)
{
	QMap<QString, QString> qmap;
	if(hashes=="md5"){
		qmap["md5"] = fileHashGenerate(path, QCryptographicHash::Algorithm::Md5);
	}else if(hashes=="sha1"){
		qmap["sha1"] = fileHashGenerate(path, QCryptographicHash::Algorithm::Sha1);
	}else if(hashes=="sha256"){
		qmap["sha256"] = fileHashGenerate(path, QCryptographicHash::Algorithm::Sha256);
	}

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
const Database &Engine::getDatabase() const
{
	return database;
}

