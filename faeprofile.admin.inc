<?php
/**
 * @file
 */

/**
 * Settings form for faeprofile.
 */
function faeprofile_settings_form() {
  $form['#tree'] = FALSE;

  $form['cron'] = array(
    '#type' => 'fieldset',
    '#title' => t('Synchronisation'),
    '#description' => t('Synchronise supervisor status.'),
    '#collapsible' => TRUE,
    '#weight' => 1,
  );

  $form['cron']['faeprofile_cron'] = array(
    '#title' => t('Keep supervisor status synchronised.'),
    '#description' => t('Use cron to synchronise user supervisor status with Find an Expert once a week.'),
    '#type' => 'checkbox',
    '#default_value' => (variable_get('faeprofile_cron', 0) == 0) ? 0 : 1,
  );

  $form['cron']['faeprofile_sync'] = array(
    '#markup' => '<a class="button" href="' . url('admin/config/people/faeprofile/update') . '">' . t('Synchronise now') . '</a><br/><br/>',
  );

	$msg = "
		<ul>
			<li>1. For multiple profiles, input something like http://www.findanexpert.unimelb.edu.au/individual/person14903|http://www.findanexpert.unimelb.edu.au/individual/person15416</li>
			<li>2. Need to press 'Save configuration' first, because Drupal needs to remember the setting, then 'Clean profiles'.</li>
		</ul>
	";
  $form['cron']['faeprofile_clean_cache_input'] = array(
    '#title' => t('Input find an expert profile uris'),
    '#description' => t($msg),
    '#type' => 'textfield',
		'#default_value' => variable_get('faeprofile_clean_cache_input', ''), 
  );

  $form['cron']['faeprofile_clean_cache'] = array(
    '#markup' => '<a class="button" href="' . url('admin/config/people/faeprofile/clean_cache') . '">' . t('Clean profiles') . '</a>',
  );


  $form['faeprofile_main'] = array(
    '#title' => t('Replace main profile tab with <em>Overview</em> from Find an Expert.'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('faeprofile_main', 0),
  );

  $form['faeprofile_faeprofile'] = array(
    '#title' => t('Append to <em>Overview</em> tab'),
    '#type' => 'checkboxes',
    '#options' => faeprofile_elements(),
    '#description' => t('All selected elements will be appended (in order listed) to the <em>Overview</em> profile tab.'),
    '#default_value' => variable_get('faeprofile_faeprofile', array()),
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
    '#weight' => -1,
  );

  return system_settings_form($form);
}
