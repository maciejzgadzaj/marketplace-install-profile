Commerce Marketplace example site installation profile
======================================================

This repo contains Drupal build script and installation profile for an example [Commerce Marketplace](https://www.drupal.org/sandbox/maciej.zgadzaj/1950386)-based site.

It includes creating example merchant role, merchant users, stores, products, product displays, payment and shipping methods.

### Usage

**1. Clone the installation profile**

```
git clone https://github.com/maciejzgadzaj/marketplace-install-profile.git
```

**2. Build your site**

Use included `install.sh` shell script to quickly build your site in the `destination_directory`:

```
cd marketplace-install-profile
./install.sh <destination_directory>
```

Using `install.sh` script is generally equivalent to executing these two commands:

```
drush make marketplace.make -y <destination_directory>
ln -s <current_directory> <destination_directory>/profiles/marketplace
```

**3. Install your site**

If it is your first install, and you don't have `settings.php` file with the database access details created yet, you might want to install it from your browser. Just access your site's URL and follow on-screen instructions.

If you have already installed your site before though, and/or have existing `settings.php` file, you can (re-)install it using `drush`:

```
drush si marketplace -y --site-name=mplace --account-name=admin --account-pass=admin
```
