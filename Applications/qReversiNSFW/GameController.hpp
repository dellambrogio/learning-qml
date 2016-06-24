
#ifndef QREVERSI_GAMECONTROLLER_HPP
#define QREVERSI_GAMECONTROLLER_HPP

#include <QObject>
#include <QDateTime>

#include <QScopedPointer>

class GameContext;

class GameController : public QObject
{
	Q_OBJECT
public:
	GameController();
	~GameController();

	Q_INVOKABLE QDateTime getCurrentDateTime() const;

	Q_INVOKABLE void newGame();

	Q_INVOKABLE void makeMove(int idx);

signals:
	void stateChanged();

private:
	QScopedPointer<GameContext> m_game;
};

#endif
