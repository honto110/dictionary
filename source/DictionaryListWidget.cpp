#include "DictionaryListWidget.h"

DictionaryListWidget::DictionaryListWidget(QWidget* parent) : QListWidget(parent)
{}

void DictionaryListWidget::setStopSearch(bool b)
{
	stopSearch = b;
}

bool DictionaryListWidget::getStopSearch()
{
	return stopSearch;
}

int DictionaryListWidget::getMaxVisibleItems()
{
	return 250;
}

void DictionaryListWidget::updateItemsSlot(QStringList strl)
{
	this->clear();
	
	if (strl.size() <= getMaxVisibleItems())
	{
		for (int i = 0; i < strl.size(); i++)
		{
			this->addItem(strl[i]);
		}

		QString status(QString::number(strl.size()) + " matches.");

		emit finishUpdateItems(status, 575, 145);
	}
	else
	{
		for (int i = 0; i < getMaxVisibleItems(); i++)
		{
			this->addItem(strl[i]);
		}

		QString status(QString::number(strl.size()) + " matches.\nOnly " + QString::number(getMaxVisibleItems()) + " are shown.");

		emit finishUpdateItems(status, 550, 135);
	}
}

void DictionaryListWidget::stopSearchSlot()
{
	stopSearch = true;
}

