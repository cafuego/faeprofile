<?php
/**
 * @file
 *
 * Available template variables are:
 *
 * $awards - An array of all awards.
 * $year   - An array of years, each of which contains an array of awards
 *           for that year. (Note: I disable it. Please see template_preprocess_faeprofile_awards)
 */
?>

<?php if ($awards): ?>
  <h3>Awards and honours</h3>
  <ul>
  <?php foreach ($awards as $award): ?>
    <li><?php print $award; ?></li>
  <?php endforeach; ?>
  </ul>
<?php endif; ?>

