
#include <QObject>
#include <QDateTime>

class GameController : public QObject
{
	Q_OBJECT
public:
	GameController();

	Q_INVOKABLE QDateTime getCurrentDateTime() const;
};

