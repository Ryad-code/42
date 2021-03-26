<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress_db' );

/** MySQL database username */
define( 'DB_USER', 'mlaouedj' );

/** MySQL database password */
define( 'DB_PASSWORD', 'password' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         '#p8LMl7<3_sF5jn(m@+l~Sx~[|Pg^wmh bmRRpo>>g%D#7^--s$q6X!lEAuhsei>');
define('SECURE_AUTH_KEY',  '6._Qw>Ttp{PO:#1C{v:_ypKh<YoYi9%b(J.eTM :rN!^R6RACN$jKin(wf.Oz]/u');
define('LOGGED_IN_KEY',    '8g;.^vilk`plC^z+y&B-NtI0DBB<bwo>;9mB5zZ<1&Rol-^-q]i6 qAadD`1]3f3');
define('NONCE_KEY',        '5bKL32]NmZB(B=.*N#R& :k?yf;`CD$H~+?S@5|ji^DFnY:I}z.FE^^kncG6F:! ');
define('AUTH_SALT',        '=qVO:e^88wzHpR=% *tliyArUG6a+r3*[nr,F6kS)x3+tsQP#{hr-7.exd6u*>+D');
define('SECURE_AUTH_SALT', 'srj?RU|0?_S$`l|+rIa/R+jL()w>O O&YxdpEerG-NZbD,#=eaba:jvHc%1Id#4e');
define('LOGGED_IN_SALT',   '*Pfq_.Eq:+QU?4jjK*Fd{#=~Be.OAXN<N%H@<gY#[M)X#U~C-B`[Ius+RyDpoe1D');
define('NONCE_SALT',       'yaod|W)Vgr*6u>yl_nyxFE#oRnby}B^%)eb?o=fr;WP!`BAZ%?se5Z[EAhw(IQIZ');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
