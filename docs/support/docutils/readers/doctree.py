# Author: Martin Blais
# Contact: blais@furius.ca
# Revision: $Revision: 21817 $
# Date: $Date: 2005-07-21 14:39:57 -0600 (Thu, 21 Jul 2005) $
# Copyright: This module has been placed in the public domain.

"""Reader for existing document trees."""

from docutils import readers, utils, transforms


class Reader(readers.Reader):

    """
    Adapt the Reader API for an existing document tree.

    The existing document tree must be passed as the ``source`` parameter to
    the `docutils.core.Publisher` initializer, wrapped in a
    `docutils.io.DoctreeInput` object::

        pub = docutils.core.Publisher(
            ..., source=docutils.io.DoctreeInput(document), ...)

    The original document settings are overridden; if you want to use the
    settings of the original document, pass ``settings=document.settings`` to
    the Publisher call above.
    """

    supported = ('doctree',)

    config_section = 'doctree reader'
    config_section_dependencies = ('readers',)

    def parse(self):
        """
        No parsing to do; refurbish the document tree instead.
        Overrides the inherited method.
        """
        self.document = self.input
        # Create fresh Transformer object, to be populated from Writer
        # component.
        self.document.transformer = transforms.Transformer(self.document)
        # Replace existing settings object with new one.
        self.document.settings = self.settings
        # Create fresh Reporter object because it is dependent on
        # (new) settings.
        self.document.reporter = utils.new_reporter(
            self.document.get('source', ''), self.document.settings)
