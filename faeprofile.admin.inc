<?php
/**
 * @file
 */

/**
 * Settings form for faeprofile.
 */
function faeprofile_settings_form() {
  $form['faeprofile_main'] = array(
    '#title' => t('Replace main profile tab with <em>Overview</em> from Find an Expert.'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('faeprofile_main', 0),
  );

  $form['faeprofile_information'] = array(
    '#title' => t('Append extra profile field to main profile tab.'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('faeprofile_information', 0),
  );

  $form['faeprofile_elements'] = array(
    '#title' => t('Find an Expert profile elements'),
    '#type' => 'checkboxes',
    '#options' => faeprofile_elements(),
    '#description' => t('Select all elements that should display as a tab on user profiles. Users will need the correct <a href="@link">permission</a> to see tabs.', array('@link' => url('admin/people/permissions', array('fragment' => 'module-faeprofile')))),
    '#default_value' => variable_get('faeprofile_elements', array()),
  );

  $form['note'] = array(
    '#markup' => t('Find an Expert information is only shown on a user profile if that user has a valid <em>Find an Expert Resource URL</em> entered in their profile.'),
  );

  return system_settings_form($form);
}
