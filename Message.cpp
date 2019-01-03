#include "Message.hpp"
void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &ms)
{
    for(auto f:ms.folders)
        f->addMsg(this);
}
void Message::remove_from_Folders()
{
    for(auto f:folders)
    {
        f->remMsg(this);
    }
}
Message::Message(const Message & ms):contents(ms.contents),folders(ms.folders)
{
    add_to_Folders(ms);
}
Message &Message::operator=(const Message &ms)
{
    remove_from_Folders();
    contents = ms.contents;
    folders = ms.folders;
    add_to_Folders(ms);
    return *this;
}
Message::~Message()
{
    remove_from_Folders();
}
void Folder::addMsg(Message* ms)
{
    messages.insert(ms);
}

void Folder::remMsg(Message *ms)
{
    messages.erase(ms);
}

void Folder::add_to_Message(const Folder &f)
{
    for(auto ms:f.messages)
        ms->folders.insert(this);
}

void Folder::remove_from_Message()
{
    for(auto ms:messages)
        ms->folders.erase(this);
}

Folder::Folder(const Folder&f):messages(f.messages)
{
    add_to_Message(f);
}

Folder& Folder::operator=(const Folder &f)
{
    remove_from_Message();
    messages = f.messages;
    add_to_Message(f);
    return *this;
}

