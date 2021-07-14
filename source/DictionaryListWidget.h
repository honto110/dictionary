#pragma once

#include <QFile>
#include <QLabel>
#include <QLineEdit>
#include <QApplication>
#include <QThread>
#include <QListWidget>
#include <QStringList>

class DictionaryListWidget : public QListWidget {
	Q_OBJECT
		
private:
	bool stopSearch = true;

public:
	DictionaryListWidget(QWidget* parent = nullptr);
	void setStopSearch(bool b);
	bool getStopSearch();
	int getMaxVisibleItems();

public slots:
	void updateItemsSlot(QStringList);
	void stopSearchSlot();
signals:
	void finishUpdateItems(QString, int, int);


};