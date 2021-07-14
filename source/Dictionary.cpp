#include "Dictionary.h"

Dictionary::Dictionary(QString path, DictionaryListWidget* dlistptr, QWidget* parent) : QObject(parent), dlist(dlistptr), pathToDict(path)
{}

void Dictionary::Search(QString substring)
{
	dlist->setStopSearch(false);
	QStringList strList;
	if (!substring.size())
	{
		emit dlist->clear();
		return;
	}

	QFile file(pathToDict);
	if (file.exists() && file.open(QIODevice::ReadOnly))
	{
		QString currentStr = "";
		while (!file.atEnd())
		{
			if (dlist->getStopSearch())
			{
				return;
			}
			currentStr = (QString)file.readLine();
			if (currentStr.contains(substring))
			{
				strList << "  " + currentStr;
			}
		}
		file.close();
		emit finishSearch(strList);
	}
	else
	{
		//error
	}
}
