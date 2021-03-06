#pragma once

#include <QTextStream>
#include <QDirIterator>
#include <QString>
#include <QStringList>

namespace utils
{

enum class Verdict
{
	Clear ,
	Threat,
	Error
};

class Utils
{
public:

	QTextStream &qStdOut()
	{

		static QTextStream textStream(stdout);
		return textStream;
	};


	QStringList fileInFolder( const QString &path )
	{
		{
			QStringList results;
			QDirIterator it(path);
			while ( it.hasNext()) {
				it.next();
				if ( QFileInfo(it.filePath()).isFile()) {
					results << it.filePath();
				}
			}

			return results;
		};
	};

};
}
