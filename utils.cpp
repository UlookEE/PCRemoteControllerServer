#include<QString>
#include<QChar>
#include<QHostAddress>

QString GetRandomString(int len)
{
   const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
   const int randomStringLength = len; // assuming you want random strings of 12 characters

   QString randomString;
   for(int i=0; i<randomStringLength; ++i)
   {
       int index = qrand() % possibleCharacters.length();
       QChar nextChar = possibleCharacters.at(index);
       randomString.append(nextChar);
   }
   return randomString;
}

QString IPToCode(QHostAddress hostAddress)
{
    QString ip = hostAddress.toString();
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");

    QString resString;

    QStringList list = ip.split(QLatin1Char('.'));

    qint32 mod = possibleCharacters.length();
    for(auto i : list){
        qint32 num = i.toInt();
        resString.append(possibleCharacters[num % mod]);
        num /=mod;
        resString.append(possibleCharacters[num % mod]);
        num /=mod;
    }
    return resString;
}
