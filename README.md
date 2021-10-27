# fusiondirectory-plugins-notes

This is a plugin for FusionDirectory that add some informations about each ldap entry.
Its useful because the description field is only a text field without any history

## Why this plugin ?

It was designed to be a light change management system for Fusiondirectoy.
FusionDirectory lack a way to get the history in the lifcycle of component.
For example : "2021-08-30 : I restarted the server due to CPU overload"

## Todo
We need to fetch the current user as the author of the notes
We need to study a way to add some rich text ( like url, bold text, or bullet point )
We need to  provide a way to disable removing and editing line .

## How to install

`git https://github.com/gallak/fusiondirectory-plugins-notes.git
mv fusiondirectory-plugins-notes notes`

### Installation of ldap schema

`ldap-schema-manager -i ./notes/contrib/schema/notes-fd.schema`

### Installation of plugin

```fusiondirectory-setup --set-fd_home=/usr/local/share/fusiondirectory --install-plugins
Setting fd_home to /usr/share/fusiondirectory
Installing FusionDirectory's plugins
Where is your plugins archive or folder?:
<complete current path>            
Available plugins:
1:notes

fusiondirectory-setup --update-cache --update-locales
```

### usage

see screenshoot

![screen of notes](example.png)


