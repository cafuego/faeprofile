<?php
/**
 * @file
 */
?>

<?php if ($affiliations): ?>
  <h3>Member of</h3>
  <ul>
  <?php foreach ($affiliations as $affiliation): ?>
    <li><?php print $affiliation; ?></li>
  <?php endforeach; ?>
  </ul>
<?php endif; ?>
