#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>
#include <QVector>
#include "src/res/settings.h"
#include "src/res/password.h"

namespace Ui {
	class InfoDialog;
}

class InfoDialog : public QDialog {
	Q_OBJECT

public:
	explicit InfoDialog(const QVector<Password> passwords, const Settings& settings, QWidget *parent = nullptr);
	~InfoDialog();

private:
	void updateLabels();

private:
	Ui::InfoDialog *ui;

	const QVector<Password> m_passwords;
	const Settings& m_settings;
};

#endif // INFODIALOG_H
