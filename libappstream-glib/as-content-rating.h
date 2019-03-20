/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2016 Richard Hughes <richard@hughsie.com>
 *
 * SPDX-License-Identifier: LGPL-2.1+
 */

#pragma once

#if !defined (__APPSTREAM_GLIB_H_INSIDE__) && !defined (AS_COMPILATION)
#error "Only <appstream-glib.h> can be included directly."
#endif

#include <glib-object.h>

G_BEGIN_DECLS

#define AS_TYPE_CONTENT (as_content_rating_get_type ())
G_DECLARE_DERIVABLE_TYPE (AsContentRating, as_content_rating, AS, CONTENT_RATING, GObject)

struct _AsContentRatingClass
{
	GObjectClass		parent_class;
	/*< private >*/
	void (*_as_reserved1)	(void);
	void (*_as_reserved2)	(void);
	void (*_as_reserved3)	(void);
	void (*_as_reserved4)	(void);
	void (*_as_reserved5)	(void);
	void (*_as_reserved6)	(void);
	void (*_as_reserved7)	(void);
	void (*_as_reserved8)	(void);
};

/**
 * AsContentRatingValue:
 * @AS_CONTENT_RATING_VALUE_UNKNOWN:		Unknown value
 * @AS_CONTENT_RATING_VALUE_NONE:		None
 * @AS_CONTENT_RATING_VALUE_MILD:		A small amount
 * @AS_CONTENT_RATING_VALUE_MODERATE:		A moderate amount
 * @AS_CONTENT_RATING_VALUE_INTENSE:		An intense amount
 *
 * The specified level of an content_rating rating ID.
 **/
typedef enum {
	AS_CONTENT_RATING_VALUE_UNKNOWN,
	AS_CONTENT_RATING_VALUE_NONE,
	AS_CONTENT_RATING_VALUE_MILD,
	AS_CONTENT_RATING_VALUE_MODERATE,
	AS_CONTENT_RATING_VALUE_INTENSE,
	/*< private >*/
	AS_CONTENT_RATING_VALUE_LAST
} AsContentRatingValue;

/**
 * AsContentRatingSystem:
 * @AS_CONTENT_RATING_SYSTEM_UNKNOWN:		Unknown rating system
 * @AS_CONTENT_RATING_SYSTEM_IARC:		International Age Rating Coalition
 * @AS_CONTENT_RATING_SYSTEM_INCAA:		Instituto Nacional de Cine y Artes Audiovisuales (Argentina)
 * @AS_CONTENT_RATING_SYSTEM_ACB:		Australian Classification Board
 * @AS_CONTENT_RATING_SYSTEM_DJCTQ:		Sistema de Classificação Indicativa Brasileiro (Brazil)
 * @AS_CONTENT_RATING_SYSTEM_GSRR:		Game Software Rating Regulations (Taiwan)
 * @AS_CONTENT_RATING_SYSTEM_PEGI:		Pan European Game Information (most of Europe, plus a handful of other countries)
 * @AS_CONTENT_RATING_SYSTEM_KAVI:		Kansallinen audiovisuaalinen instituutti (Finland)
 * @AS_CONTENT_RATING_SYSTEM_USK:		Unterhaltungssoftware Selbstkontrolle
 * @AS_CONTENT_RATING_SYSTEM_ESRA:		Entertainment Software Rating Association (Iran)
 * @AS_CONTENT_RATING_SYSTEM_CERO:		Computer Entertainment Rating Organization (Japan)
 * @AS_CONTENT_RATING_SYSTEM_OFLCNZ:		Office of Film and Literature Classification (New Zealand)
 * @AS_CONTENT_RATING_SYSTEM_RUSSIA:		Russian content rating law
 * @AS_CONTENT_RATING_SYSTEM_MDA:		Media Development Authority (Singapore)
 * @AS_CONTENT_RATING_SYSTEM_GRAC:		Game Rating and Administration Committee (South Korea)
 * @AS_CONTENT_RATING_SYSTEM_ESRB:		Entertainment Software Rating Board (the rating system used in North America)
 * @AS_CONTENT_RATING_SYSTEM_IGRS:		Indonesian Game Rating System
 */
typedef enum {
	AS_CONTENT_RATING_SYSTEM_UNKNOWN,
	AS_CONTENT_RATING_SYSTEM_IARC,
	AS_CONTENT_RATING_SYSTEM_INCAA,
	AS_CONTENT_RATING_SYSTEM_ACB,
	AS_CONTENT_RATING_SYSTEM_DJCTQ,
	AS_CONTENT_RATING_SYSTEM_GSRR,
	AS_CONTENT_RATING_SYSTEM_PEGI,
	AS_CONTENT_RATING_SYSTEM_KAVI,
	AS_CONTENT_RATING_SYSTEM_USK,
	AS_CONTENT_RATING_SYSTEM_ESRA,
	AS_CONTENT_RATING_SYSTEM_CERO,
	AS_CONTENT_RATING_SYSTEM_OFLCNZ,
	AS_CONTENT_RATING_SYSTEM_RUSSIA,
	AS_CONTENT_RATING_SYSTEM_MDA,
	AS_CONTENT_RATING_SYSTEM_GRAC,
	AS_CONTENT_RATING_SYSTEM_ESRB,
	AS_CONTENT_RATING_SYSTEM_IGRS,
	/*< private >*/
	AS_CONTENT_RATING_SYSTEM_LAST
} AsContentRatingSystem;

AsContentRating	*as_content_rating_new		(void);

/* helpers */
const gchar	*as_content_rating_value_to_string	(AsContentRatingValue	 value);
AsContentRatingValue	 as_content_rating_value_from_string	(const gchar	*value);

/* getters */
const gchar	*as_content_rating_get_kind	(AsContentRating	*content_rating);
guint		 as_content_rating_get_minimum_age (AsContentRating	*content_rating);
AsContentRatingValue as_content_rating_get_value (AsContentRating	*content_rating,
						 const gchar		*id);

const gchar	**as_content_rating_get_rating_ids (AsContentRating	*content_rating);

guint		as_content_rating_attribute_to_csm_age (const gchar		*id,
							AsContentRatingValue 	 value);
AsContentRatingValue as_content_rating_value_for_csm_age (const gchar		*id,
							  guint 		 age);
const gchar    *as_content_rating_attribute_to_description (const gchar          *id,
							    AsContentRatingValue  value);
const gchar	**as_content_rating_get_all_rating_ids (void);

/* setters */
void		 as_content_rating_set_kind	(AsContentRating	*content_rating,
						 const gchar		*kind);
void		 as_content_rating_add_attribute(AsContentRating	*content_rating,
						 const gchar		*id,
						 AsContentRatingValue	 value);

/* content rating systems  */
AsContentRatingSystem  as_content_rating_system_from_locale (const gchar           *locale);
const gchar           *as_content_rating_system_to_string   (AsContentRatingSystem  system);
const gchar           *as_content_rating_system_age_to_str  (AsContentRatingSystem  system,
							     guint                  age,
							     gboolean               round_up,
							     const gchar           *locale);

const gchar * const   *as_content_rating_system_get_categories (AsContentRatingSystem   system,
								const gchar            *locale,
								const guint           **ages,
								gsize                  *n_levels);

G_END_DECLS
