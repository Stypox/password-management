#ifndef SETTINGS_H
#define SETTINGS_H
#include <QJsonObject>
#include "resources.h"
#include "password.h"


struct Settings {
	Settings();

	bool load(const QJsonObject& settingsJson);
	bool load(const res::Lang& Language = res::Lang::def, const bool& ReorderingActive = false, const bool& DarkThemeActive = false, const bool& RemovalConfirmationDialogActive = true, const bool& PwnedActive = false);
	QJsonValue toJson() const;
	void reset();

	void debug() const;

	bool loaded;

	res::Lang language;
	bool reorderingActive;
	bool darkThemeActive;
	bool removalConfirmationDialogActive;
	bool pwnedActive;
};

struct UserData {
	QString username;
	QByteArray password;
};

bool extractData(const QByteArray& dataJson, Settings& settings, QVector<Password>& passwords);
QByteArray buildData(const Settings& settings, const QVector<Password>& passwords);

#endif // SETTINGS_H
