<?php
/**
 * @file
 */
?>

<h3 class="title">Supervision</h3>

<?php if ($available): ?>
  <?php print $available; ?> for supervision.
<?php endif; ?>

<?php if ($supervision): ?>
  <h4>Supervision Statement</h4>
  <p><?php print $supervision; ?></p>
<?php endif; ?>
