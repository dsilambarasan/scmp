# scmp

Used d8-skeleton to create the application.

Place the scmp_service module into web/modules/custom

Place core.extension.yml and views.view.article_feed.yml into config/sync folder

Enable scmp_service module and drush cim to import the view configuration.

Client php file to call service.
File: client.php

Change the username and password in client.php file according the account created in the drupal service.

Either use browser or command line to execute php.

browser:  localhost/client.php
command line: php client.php
