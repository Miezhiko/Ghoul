// Copyright (C) 2024 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only WITH Qt-GPL-exception-1.0

#pragma once

#include <dsthememanager.h>
#include <externaldependenciesinterface.h>

#include <QStringList>

namespace QmlDesigner {
class ExternalDependenciesInterface;

class DESIGNSYSTEM_EXPORT DSStore
{
    Q_DECLARE_TR_FUNCTIONS(DSStore)

public:
    DSStore(ExternalDependenciesInterface &ed, ProjectStorageDependencies projectStorageDependencies);
    ~DSStore();

    QString moduleImportStr() const;

    std::optional<QString> load();
    std::optional<QString> load(const Utils::FilePath &dsModuleDirPath);

    std::optional<QString> save(bool mcuCompatible = false);
    std::optional<QString> save(const Utils::FilePath &moduleDirPath, bool mcuCompatible = false);

    size_t collectionCount() const { return m_collections.size(); }

    DSThemeManager *addCollection(const QString &qmlTypeName);
    DSThemeManager *collection(const QString &typeName);
    std::optional<QString> typeName(DSThemeManager *collection) const;
    bool removeCollection(const QString &name);
    bool renameCollection(const QString &oldName, const QString &newName);

    std::optional<Utils::FilePath> moduleDirPath() const;
    QStringList collectionNames() const;

private:
    QString uniqueCollectionName(const QString &hint) const;
    std::optional<QString> loadCollection(const QString &typeName, const Utils::FilePath &qmlFilePath);
    std::optional<QString> writeQml(const DSThemeManager &mgr,
                                    const QString &typeName,
                                    const Utils::FilePath &targetDir,
                                    bool mcuCompatible);

private:
    ExternalDependenciesInterface &m_ed;
    ProjectStorageDependencies m_projectStorageDependencies;
    DSCollections m_collections;
};
} // namespace QmlDesigner