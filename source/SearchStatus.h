#pragma once

#include <QLabel>

class SearchStatus : public QLabel {
	Q_OBJECT

public:
	SearchStatus(QWidget* parent = nullptr);

public slots:
	void changeStatus(QString, int, int);
	void setSearchStatus(QString);
};