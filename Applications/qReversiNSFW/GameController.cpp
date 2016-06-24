
#include "GameController.hpp"


GameController::GameController()
	: QObject()
{

}

QDateTime GameController::getCurrentDateTime() const {
	return QDateTime::currentDateTime();
}
