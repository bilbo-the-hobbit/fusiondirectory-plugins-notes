<?php
/*
  This code is part of FusionDirectory (http://www.fusiondirectory.org/)
  Copyright (C) 2016-2017  FusionDirectory
  Copyright (C) 2021  Antoine Gallavardin

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
 */



class notes extends simplePlugin
{

  protected $displayHeader  = TRUE;
  protected $loaded = FALSE;

  static function plInfo (): array
  {
    return [
      'plShortName'   => _('notes'),
      'plDescription' => _('Notes'),
      'plPriority'    => 30,
      'plObjectClass' => ['fdNotesObject'],
      'plObjectType'  => ['workstation','server','user','component','printer','terminal','mobilephone','country','group','phone','locality'],
      'plProvidedAcls'  => parent::generatePlProvidedAcls(static::getAttributesInfo())
    ];
  }

  static function getAttributesInfo (): array
  {
    return [
      'notes' => [
        'name'  => _('Notes'),
        'class' => ['fullwidth'],
        'attrs' => [
          new OrderedArrayAttribute(
            new PipeSeparatedCompositeAttribute(
              _('Use this to hide some menu entry to specific groups of users'),
              'fdNotes',
              [
		new HiddenAttribute('fdNotes_date',TRUE,date("Y-m-d h:i:s")),
                new TextAreaAttribute(
                  _('Notes'), _('Notes'),
                  'Notes', TRUE
                ),
                //FIXME  how to get current connected user ?
                new HiddenAttribute('fdNotes_author',TRUE, "Unknown"),
              ],
              '',
              ''
            ),
            // no order
            FALSE,
            [],
            TRUE
          ),
        ]
      ],
    ];
  }
}
