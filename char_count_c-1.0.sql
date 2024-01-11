\echo Use "CREATE EXTENSION char_count" to load this file. \quit
CREATE FUNCTION char_count_c(TEXT, TEXT) RETURNS INTEGER
AS '$libdir/char_count_c'
LANGUAGE C IMMUTABLE STRICT
