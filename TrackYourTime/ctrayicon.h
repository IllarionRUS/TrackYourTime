/*
 * TrackYourTime - cross-platform time tracker
 * Copyright (C) 2015-2016  Alexander Basov <basovav@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CTRAYICON_H
#define CTRAYICON_H

#include <QObject>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QVector>
#include <QAction>
#include "cdatamanager.h"

class cTrayIcon : public QSystemTrayIcon
{
    Q_OBJECT
protected:
    cDataManager*       m_DataManager;
    QMenu               m_Menu;

    void rebuildMenu();
public:
    cTrayIcon(cDataManager* DataManager);

signals:
    void showSettings();
    void showStatistic();
    void showApplications();
    void showAbout();
public slots:
    void setActive();
    void setInactive();
    void showHint(QString text);
    void onProfilesChange();
    void onMenuSelection(QAction* menuAction);
    void onTrayTriggered(QSystemTrayIcon::ActivationReason reason);
};

#endif // CTRAYICON_H
