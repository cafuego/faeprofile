<?php
/**
 * Overview, Affiliation, Publications, Research, Awards, Linkages, Supervision.
 */

/**
 * Page callback for Find an Expert profile information.
 */
function faeprofile_page_overview($account) {
  if (empty($account->field_fae_resource['und'][0]['url'])) {
    return drupal_not_found();
  }

  // $overview = uom_fae_api_person(basename($account->field_fae_resource['und'][0]['url']));

  $contact = uom_fae_api_person_contact($account->field_fae_resource['und'][0]['url']);
  dpm($contact);

  return t('');
}
