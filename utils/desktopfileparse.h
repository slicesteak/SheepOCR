#ifndef DESKTOPFILEPARSE_H
#define DESKTOPFILEPARSE_H
#include <QIcon>
#include <QStringList>
#include <QMap>
class QDir;
class QString;
class QTextStream;
struct DesktopAppData
{
	DesktopAppData() : showInTerminal() {}
    DesktopAppData(QString name, QString description, QString exec, QIcon icon) : name(name), description(description), exec(exec), icon(icon), showInTerminal(false)
    {

    }
    bool operator==(const DesktopAppData &other) const
    {
		return name == other.name;
	}
    QString name;
    QString description;
    QString exec;
	QStringList categories;
	QIcon icon;
	bool showInTerminal;
};
struct DesktopFileParser
{
	DesktopFileParser();
	DesktopAppData parseDesktopFile(const QString &fileName, bool &ok) const;
	int processDirectory(const QDir &dir);
	QList<DesktopAppData> getAppsByCategory(const QString &category);
    QMap<QString, QList<DesktopAppData>> getAppsByCategory(const QStringList &categories);
private:
    QString m_localeName;
    QString m_localeDescription;
    QString m_localeNameShort;
    QString m_localeDescriptionShort;
	QIcon m_defaultIcon;
	QList<DesktopAppData> m_appList;
};
#endif



























