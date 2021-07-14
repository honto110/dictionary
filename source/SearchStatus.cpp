#include "SearchStatus.h"

SearchStatus::SearchStatus(QWidget* parent) : QLabel(parent)
{}

void SearchStatus::changeStatus(QString str, int x, int y)
{
	this->setText(str);
	QFont statusFont("Times", 12);
	this->move(x, y);
	this->setFont(statusFont);
	this->adjustSize();
}

void SearchStatus::setSearchStatus(QString str)
{
	if (str.size() == 0)
	{
		this->setText("");
		this->adjustSize();
	}
	else
	{
		this->setText("...");
		QFont statusFont("Times", 20);
		this->move(600, 135);
		this->setFont(statusFont);
		this->adjustSize();
	}
}
