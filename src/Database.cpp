#include "Database.h"


Database::Database()
{
	if(connectToDatabase()) {
		init();
	}
}

bool Database::connectToDatabase()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	QString path = QDir::currentPath() + "/DatabaseDb.sqlite3";
	db.setDatabaseName(path);
	if (!db.open()) {
		qDebug() << "Faild to open database.";
		return false;
	}

	return true;
}

bool Database::findInDatabase(const QString &md5, const QString &sha1, const QString &sha256)
{
	QSqlQuery sqlQuery;

	sqlQuery.prepare(
		"SELECT md5, sha1, sha256 FROM Hashes WHERE md5 = (:md5Var) OR sha1 = (:sha1Var) OR sha256 = (:sha256Var)");
	sqlQuery.bindValue(":md5Var", md5);
	sqlQuery.bindValue(":sha1Var", sha1);
	sqlQuery.bindValue(":sha256Var", sha256);

	return (sqlQuery.exec() && sqlQuery.next());
}

bool Database::findInDatabase(const QString &hash)
{
	QSqlQuery sqlQuery;
	sqlQuery.prepare("SELECT md5 FROM Hashes WHERE md5 = (:md5) OR sha1 = (:sha1) OR sha256 = (:sha256)");
	sqlQuery.bindValue(":md5", hash);
	sqlQuery.bindValue(":sha1", hash);
	sqlQuery.bindValue(":sha256", hash);

	return (sqlQuery.exec() && sqlQuery.next());
}

void Database::addRecord(const QString &md5Path, const QString &sha1Path, const QString &sha256Path, const QString &name)
{

	QSqlQuery sqlQuery;

	sqlQuery.prepare("INSERT INTO Hashes (md5, sha1, sha256, File_name) VALUES (:md5Path, :sha1Path, :sha256Path, :name)");
	sqlQuery.addBindValue(md5Path);
	sqlQuery.addBindValue(sha1Path);
	sqlQuery.addBindValue(sha256Path);
	sqlQuery.addBindValue(name);

	if (!sqlQuery.exec()) {
		qDebug() << "Error while inserting data into Hashes table";
	}
}

bool Database::init()
{
	QSqlQuery sqlQuery;

	sqlQuery.prepare("CREATE TABLE IF NOT EXISTS Hashes(md5 TEXT, sha1 TEXT, sha256 TEXT, File_name TEXT)");
	if (!sqlQuery.exec()) {
		qDebug() << "Error creating table: " << sqlQuery.lastError();
		return false;
	}
	return true;
}