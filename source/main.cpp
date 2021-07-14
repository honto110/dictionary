#include "Dictionary.h"
#include "SearchStatus.h"

int main(int argc, char *argv[])
{
    const QString dictPath = "words.txt";

    QApplication app(argc, argv);
    QPixmap iconPixmap("icon.jpg");
    QIcon icon(iconPixmap);
    app.setWindowIcon(icon);

    QThread* dictThread = new QThread();
    
    QWidget wgt;
    wgt.setWindowTitle("Dictionary");
    wgt.resize(720, 900);
    wgt.setMaximumSize(720, 900);
    wgt.setMinimumSize(720, 900);

    QLabel* searchLabel = new QLabel("Search", &wgt);
    QFont searchLabelFont("Times", 17);
    searchLabel->setFont(searchLabelFont);
    searchLabel->move(25, 22);

    QLineEdit* lnEdit = new QLineEdit(&wgt);
    QFont lnEditFont("Times", 18);
    lnEdit->setFont(lnEditFont);
    lnEdit->move(10, 70);
    lnEdit->resize(700, 50);

    DictionaryListWidget* dictList = new DictionaryListWidget(&wgt);
    dictList->setFrameStyle(QFrame::NoFrame);
    dictList->setFont(searchLabelFont);
    dictList->move(0, 190);
    dictList->resize(720, 710);
    
    SearchStatus* status = new SearchStatus(&wgt);
    
    Dictionary dict(dictPath, dictList);
    dict.moveToThread(dictThread);

    QObject::connect(lnEdit, SIGNAL(textEdited(QString)),
                    &dict, SLOT(Search(QString))
    );

    QObject::connect(lnEdit, SIGNAL(textEdited(QString)),
        dictList, SLOT(stopSearchSlot())
    );

    QObject::connect(&dict, SIGNAL(finishSearch(QStringList)),
        dictList, SLOT(updateItemsSlot(QStringList))
    );

    QObject::connect(lnEdit, SIGNAL(textEdited(QString)),
        status, SLOT(setSearchStatus(QString))
    );

    QObject::connect(dictList, SIGNAL(finishUpdateItems(QString, int, int)),
        status, SLOT(changeStatus(QString, int, int))
    );

    dictThread->start();
    wgt.show();
   
    return app.exec();
}
