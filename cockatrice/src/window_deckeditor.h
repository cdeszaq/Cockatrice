#ifndef WINDOW_DECKEDITOR_H
#define WINDOW_DECKEDITOR_H

#include <QMainWindow>
#include <QAbstractItemModel>
#include "decklist.h"

class CardDatabase;
class CardDatabaseModel;
class DeckListModel;
class QTreeView;
class QTableView;
class CardInfoWidget;
class QLineEdit;
class QTextEdit;

class WndDeckEditor : public QMainWindow {
	Q_OBJECT
private slots:
	void updateName(const QString &name);
	void updateComments();
	void updateCardInfoLeft(const QModelIndex &current, const QModelIndex &previous);
	void updateCardInfoRight(const QModelIndex &current, const QModelIndex &previous);
	void updateSearch(const QString &search);

	void actNewDeck();
	void actLoadDeck();
	bool actSaveDeck();
	bool actSaveDeckAs();
	void actPrintDeck();

	void actEditSets();

	void actAddCard();
	void actAddCardToSideboard();
	void actRemoveCard();
	void actIncrement();
	void actDecrement();
private:
	void addCardHelper(const QString &zoneName);
	void recursiveExpand(const QModelIndex &index);
	bool confirmClose();

	QString lastFileName;
	DeckList::FileFormat lastFileFormat;
	CardDatabase *db;

	CardDatabaseModel *databaseModel;
	DeckListModel *deckModel;
	QTreeView *databaseView;
	QTreeView *deckView;
	CardInfoWidget *cardInfo;
	QLineEdit *searchEdit, *nameEdit;
	QTextEdit *commentsEdit;

	QMenu *deckMenu, *setsMenu;
	QAction *aNewDeck, *aLoadDeck, *aSaveDeck, *aSaveDeckAs, *aPrintDeck, *aClose;
	QAction *aEditSets;
	QAction *aAddCard, *aAddCardToSideboard, *aRemoveCard, *aIncrement, *aDecrement;
public:
	WndDeckEditor(CardDatabase *_db, QWidget *parent = 0);
	~WndDeckEditor();
protected:
	void closeEvent(QCloseEvent *event);
};

#endif