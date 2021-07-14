#pragma once

#include "DictionaryListWidget.h"

class Dictionary : public QObject {
	Q_OBJECT

private:
	QString pathToDict;
	DictionaryListWidget* dlist;
	bool updateSearch = false;

public:
	Dictionary(QString path, DictionaryListWidget* dlistptr, QWidget* parent = nullptr);

public slots:
	void Search(QString substring);

signals:
	void finishSearch(QStringList);
};