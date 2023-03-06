#include <QFuture>
#include <QPromise>
static void readDiffPatch(QPromise<QList<FileData>> &promise, QStringView patch)
            if (promise.isCanceled())
                return;
                const FileData fileData = readDiffHeaderAndChunks(headerAndChunks, &readOk);
            const FileData fileData = readDiffHeaderAndChunks(headerAndChunks, &readOk);
        return;
    promise.addResult(fileDataList);
static void readGitPatch(QPromise<QList<FileData>> &promise, QStringView patch)
        if (promise.isCanceled())
            return;
        if (!detectFileData(fileDiff, &fileData, &remainingFileDiff))
            return;
    promise.setProgressRange(0, patches.size());
    bool readOk = false;
        if (promise.isCanceled())
            return;
        promise.setProgressValue(i++);
            return;
    promise.addResult(fileDataList);
}
std::optional<QList<FileData>> DiffUtils::readPatch(const QString &patch)
{
    QPromise<QList<FileData>> promise;
    promise.start();
    readPatchWithPromise(promise, patch);
    if (promise.future().resultCount() == 0)
    return promise.future().result();
void DiffUtils::readPatchWithPromise(QPromise<QList<FileData>> &promise, const QString &patch)
    promise.setProgressRange(0, 1);
    promise.setProgressValue(0);
    readGitPatch(promise, croppedPatch);
    if (promise.future().resultCount() == 0)
        readDiffPatch(promise, croppedPatch);