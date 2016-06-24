
#ifndef QREVERSI_GAMECONTROLLER_HPP
#define QREVERSI_GAMECONTROLLER_HPP

#include <QObject>
#include <QVector>

#include <QScopedPointer>

namespace rv {
	class Reversi;
}

class GameController : public QObject
{
	Q_OBJECT
	Q_PROPERTY(int currentPlayer READ getCurrentPlayer NOTIFY currentPlayerChanged)
	Q_PROPERTY(QVector<int> currentValidMoves READ getCurrentValidMoves NOTIFY currentValidMovesChanged)
	Q_PROPERTY(int numBlackStones READ getNumBlackStones NOTIFY numBlackStonesChanged)
	Q_PROPERTY(int numWhiteStones READ getNumWhiteStones NOTIFY numWhiteStonesChanged)

public:
	GameController();
	~GameController();

	Q_INVOKABLE void newGame();

	Q_INVOKABLE void makeMove(int idx);

	int getCurrentPlayer() const;
	const QVector<int> &getCurrentValidMoves() const;
	int getNumBlackStones() const;
	int getNumWhiteStones() const;

private:
	void setCurrentPlayer(int currentPlayer);
	void setCurrentValidMoves(const QVector<int> &currentValidMoves);
	void setNumBlackStones(int numBlackStones);
	void setNumWhiteStones(int numWhiteStones);

signals:
	void currentPlayerChanged();
	void currentValidMovesChanged();
	void numBlackStonesChanged();
	void numWhiteStonesChanged();

private:
	int m_currentPlayer;
	QVector<int> m_currentValidMoves;
	int m_numBlackStones;
	int m_numWhiteStones;

	QScopedPointer<rv::Reversi> m_game;
};

#endif
